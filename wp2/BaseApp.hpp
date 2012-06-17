#ifndef WP2_BASEAPP_HPP
#define WP2_BASEAPP_HPP

#include <string>
#include <Wt/WApplication>
#include <Wt/Dbo/backend/Postgres>
#include <Wt/Dbo/Session>

namespace wp2 {

/** The base class for all wp2 applications.
  * One must derive from this in order to use wp2 features.
  */
class BaseApp : public Wt::WApplication {
private:
    Wt::Dbo::Session _db;
    Wt::Dbo::backend::Postgres _postgres;
protected:
    /// Call this in your constructor before using db()
    void connectDB(const std::string& postgresConnectionString) {
        _postgres.connect(postgresConnectionString);
        _db.setConnection(_postgres);
    }
public:
    BaseApp(const Wt::WEnvironment& env) : Wt::WApplication(env), _db() {}
    Wt::Dbo::Session& db() { return _db; }
};

} // namespace wp2

#endif // WP2_BASEAPP_HPP
